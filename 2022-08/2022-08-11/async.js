function foo() {
	var change;
	setTimeout(() => {
		console.log(1);
		change();
	}, Math.floor(Math.random() * 500));

	return function () {
		change = function () {
			console.log("hello");
		};
	};
}
process.stdout.write("hello node!");
foo()();
// setTimeout(() => {
// 	console.log(2);
// }, Math.floor(Math.random()*500));
// setTimeout(() => {
// 	console.log(3);
// }, Math.floor(Math.random()*500));

module.exports = function async() {
	function addAsync(x, y, cb) {}
	var thunk = function (cb) {
		addAsync(10, 15, cb);
	};
	thunk(function (sum) {
		console.log(sum);
	});
};
