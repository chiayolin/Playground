// Require the HTTP module
var http = require('http');

http.createServer(function(request, response) {
  response.writeHead(200); // Status code in header
  response.write("hello, world"); // Response body
  response.end(); // Close the connection
}).listen(8080); // Listen for connections on port 8080

console.log('Listening on port 8080...');


