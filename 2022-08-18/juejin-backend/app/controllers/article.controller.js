const fakeInfo = [
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
	{ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" },
];
const fakeDetail = [
	{
		id: 1,
		title: "vue进阶",
		author: "尤雨溪",
		date: "166893729874",
		content: "<h1>helloworld</h1>",
	},
	{
		id: 1,
		title: "vue进阶",
		author: "尤雨溪",
		date: "166893729874",
		content: "<h1>helloworld</h1>",
	},
	{
		id: 1,
		title: "vue进阶",
		author: "尤雨溪",
		date: "166893729874",
		content: "<h1>helloworld</h1>",
	},
	{
		id: 1,
		title: "vue进阶",
		author: "尤雨溪",
		date: "166893729874",
		content: "<h1>helloworld</h1>",
	},
	{
		id: 1,
		title: "vue进阶",
		author: "尤雨溪",
		date: "166893729874",
		content: "<h1>helloworld</h1>",
	},
];
exports.findInfo = (req, res) => {
	var articleId = req.query.id;
	// console.log(articleId);

	res.send(fakeInfo[articleId]);
};

exports.findDetail = (req, res) => {
	var articleId = req.query.id;
	// console.log(articleId);

	res.send(fakeDetail[articleId]);
};
