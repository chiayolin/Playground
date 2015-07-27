obj = Object.new
if obj.respond_to?("talk")
  puts "i know how to talk"
else
  puts "idk how to talk"
end
