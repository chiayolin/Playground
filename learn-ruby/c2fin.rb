puts "reading celsius temperature value from data file..."
num = File.read("c2fin.dat")
celsius = num.to_i
fahrenheit = (celsius * 9 / 5) + 32
print "Result: "
puts fahrenheit
