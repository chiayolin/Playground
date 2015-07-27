# create a ticket
ticket = Object.new
def ticket.venue
  "SSIS"
end
def ticket.performer
  "Jakob Dylan"
end
def ticket.price
  25.55
end

# get user input
print "search ticket information: "
request = gets.chomp # "chomps" off trailing '\n'

if request == "venue"
  puts ticket.venue
elsif request == "performer"
  puts ticket.performer
elsif request == "price"
  puts ticket.price
else
  puts "error: \"#{request}\" not found"
end
