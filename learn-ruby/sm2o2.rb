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

print "search ticket information: "
request = gets.chomp

if ticket.respond_to?(request)
  puts ticket.send(request)
else
  puts "error \"#{request}\" not found"
end
