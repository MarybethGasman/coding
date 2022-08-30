module.exports = (app) => {
	const articles = require("../controllers/probe");
	var router = require("express").Router();
	router.get("/probe.gif", articles.probeHandle);
	app.use("/", router);
};
