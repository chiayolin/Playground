print "hey, go enter a celsius value: "
celsius = gets.to_i
fahrenheit = (celsius * 9 / 5) + 32
puts "saving input to 'c2fout.dat'"
fh = File.new("c2fout.dat", "w")
fh.puts fahrenheit 
fh.close
