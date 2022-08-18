exports.probeHandle = (req, res) => {
	// var articleId = req.query.id;
	console.log(req.query);

	res.send({ msg: "请求成功" });
};
