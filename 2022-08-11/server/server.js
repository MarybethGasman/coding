// var async = require("./async")
// async();
var express = require("express");
var expressWs = require("express-ws");
var expressWs = expressWs(express());
var app = expressWs.app;

app.use(express.static("../public"));

app.ws("/", function (ws, req) {
	console.log("Socket Connected");

	ws.route = "/"; /* <- Your path */

	ws.onclose = function (event) {
		console.log("websocket connection closed", event);
	};

	ws.onmessage = function (msg) {
		console.log(msg.data);

		Array.from(expressWs.getWss().clients)
			.filter((sock) => {
				return sock.route == "/"; /* <- Your path */
			})
			.forEach(function (client) {
				client.send(msg.data);
			});
	};
});

app.listen(3000);
