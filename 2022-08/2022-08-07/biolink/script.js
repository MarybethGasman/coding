var a = 10;
var b = 10;

var add = (a, b) => a + b;
function add5(a) {
	var b = a;
	return (a) => {
		return a + b;
	};
}
class Dog {
	constructor() {}
	A = function () {
		var a;
		console.log(a);
	};
	B = function () {
		var b;
		console.log(b);
	};
}
var dog = new Dog();
dog.A();

// function A() {
// 	var a;
// 	console.log(a);
//     B();
// }
// function B() {
// 	var b;
// 	console.log(b);
// }
