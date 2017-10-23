from threading import Timer
import tkinter, sys, os, time

class Window(tkinter.Tk):
    
    def __init__(self):
        tkinter.Tk.__init__(self)
        self.title("Take Control")
        self.geometry("420x200")
        
        # night shift button layout
        self.ns_btn = tkinter.Button(text = "Night Shift", command = self.night_shift)
        self.ns_btn.pack(fill = tkinter.BOTH, expand = 1)
        self.ns_btn.grid(row = 2, column = 0, columnspan=2)
        
        # timer slider layout
        self.tm_sld = tkinter.Scale(self, from_ = 5, to = 60, length = 320,
            tickinterval = 10, orient = tkinter.HORIZONTAL)
        self.tm_sld.set(22)
        self.tm_sld.pack(fill = tkinter.BOTH, expand = 1)
        self.tm_sld.grid(row = 3, column = 0)

        self.tm_btn = tkinter.Button(text = "Start Timer", command = self.timer)
        self.tm_btn.pack(fill = tkinter.BOTH, expand = 1)
        self.tm_btn.grid(row = 3, column = 1)

    def notificator(self, interval, minutes):
        os.system("terminal-notifier -title TakeControl -message" + \
                    (" \"You have %d minutes left\"" % (interval - minutes)))

    def kill_login(self):
        os.system("pmset sleepnow")

    def night_shift(self):
        os.system(
            """
            osascript <<'END'
            
            tell application "System Preferences"
                activate
                reveal anchor "displaysNightShiftTab" of pane id "com.apple.preference.displays"
                delay 0.5
            end tell
            
            tell application "System Events"
                tell process "System Preferences"
                    click checkbox 1 of tab group 1 of window 1
                end tell
            end tell
            
            tell application "System Preferences"
                quit
            end tell
            
            END
            """
        )
    
    def timer(self):
        interval = int(self.tm_sld.get())
        notify_time = [*map(lambda r: int(r * interval), [1 - .1, 1 - .25, 1 - .5])]

        threads = []
        for time in notify_time:
            print(time)
            threads += [Timer(time, self.notificator, [interval, time])]
        threads += [Timer(interval, self.kill_login)]
        
        for thread in threads:
            print(thread)
            thread.start()

        print("timer set")

if __name__ == "__main__":
    application = Window()
    application.mainloop()

