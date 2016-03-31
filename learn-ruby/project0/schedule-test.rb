#date = Time.new.strftime("%Y%m%d")
date = "20150911"
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

puts "Good morning Chiayo,\n\n"
puts "Today is a #{data[0]} (#{data[1]}).\n\n"
puts "Have a nice day,"
puts "Your Mighty Script"
