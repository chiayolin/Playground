require 'telegram_bot'
require 'pp'
require 'logger'


########
date = Time.new.strftime("%Y%m%d")
start = Array.new
finish = Array.new

f = File.open("./basic.ics", "r")

# get starting and ending line numbers
f.each_line do |line|
  if line.include? date and line.start_with? "DTSTART"
    start.push(f.lineno)
    f.each_line.next until \
      f.each_line.next.include? "END:VEVENT"
    finish.push(f.lineno)
  end
end

# get block data from known line numbers
data = Array.new
start.zip(finish).each do |from, to|
  f.rewind
  (from - 2).times {f.gets}
  f.each_line do |block|
    if f.lineno <= to and block.include? "SUMMARY"
      data.push(block.strip.split("SUMMARY:").last)
    end
  end
end

#p start
#p finish
data = data.uniq

p data

# clean up the strings before printing
data.reverse if data[0].include? "Day"
data.each { |item| item.gsub!(/HS /, '')}

puts "/schedule"

## telegram
logger = Logger.new(STDOUT, Logger::DEBUG)

bot = TelegramBot.new(token: '165782513:AAE1U4Fe6k66oqn1Cfbhe7Pwg9Gl0t0ZTx4', logger: logger)
logger.debug "starting telegram bot"

bot.get_updates(fail_silently: true, timeout: 10000) do |message|
  puts "updates!!!"
  logger.info "@#{message.from.username}: #{message.text}"
  command = message.get_command_for(bot)

  message.reply do |reply|
    case command
    when /joke/i
      reply.text = "You <3"
    when /start|hello/i
      reply.text = "Greetings! I'm Eleanor Rigby. I was created by Chiayo Lin on March 20th, 2016.\n\nYou can control me by sending these commands:\n\n" + \
        "/help - print available commands\n" + "/schedule - print SSIS day schedule\n" + "/greet - greet to the user!"
    when /greet/i
      reply.text = "Hello, #{message.from.first_name}!"
    when /schedule/i
      reply.text = "Today is a #{data[0]} (#{data[1]})."
    else
      reply.text = "#{message.from.first_name}, have no idea what #{command.inspect} means."
    end
    logger.info "sending #{reply.text.inspect} to @#{message.from.username}"
    reply.send_with(bot)
  end
end

