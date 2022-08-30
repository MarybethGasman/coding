fetch("http://124.223.112.154/me.md")
	.then((res) => {
		// console.log(res);
		return res.text();
	})
	.then((data) => {
		console.log(data);
	})
	.catch((err) => {
		console.log(err);
	});
