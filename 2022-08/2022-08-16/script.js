var chatList = document.querySelector("#chat-list");
var sendBtn = document.querySelector("#send-btn");
var cnt = 0;
sendBtn.addEventListener("click", () => {
	appendHtml(chatList, `<li>${cnt++}</li>`);
});
function appendHtml(el, str) {
	var div = document.createElement("div");
	div.innerHTML = str;
	while (div.children.length > 0) {
		el.appendChild(div.children[0]);
	}
}
// fcp
// const observer = new PerformanceObserver((list) => {
// 	for (const entry of list.getEntries()) {
// 		console.log(entry);
// 	}
// });
// observer.observe({ entryTypes: ["paint"] });
// 语法错误使用ESLint解决，不要带到线上
// 一般的可预测的错误可以使用try-catch捕获
// 异步错误 window.onerror
// promise 错误 window unhandledrejection事件
// 图片网络请求错误 如img src 404 window error事件
new Promise((resolve, reject) => {
	reject("promise 错误");
});
window.addEventListener("unhandledrejection", (event) => {
	event.preventDefault();
	console.log(event);
});
window.addEventListener(
	"error",
	function (msg, url, row, col, error) {
		console.log(msg, url, row, col, error);
		return true;
	},
	true
);
window.onerror = function (msg, url, row, col, error) {
	console.log(msg, url, row, col, error);
	return true;
};
function test() {
	var num = "123";
	num++;
	error;
	console.log(num);
	return "test";
}
//AOP 切面，利用原型链
Function.prototype.before = function (fn) {
	var __self = this;
	return function () {
		fn.apply(this, arguments);
		return __self.apply(__self, arguments);
	};
};
Function.prototype.after = function (fn) {
	var __self = this;
	return function () {
		var ret = __self.apply(__self, arguments);
		fn.apply(this, arguments);
		return ret;
	};
};

console.log(
	test
		.before(function () {
			//前
		})
		.after(function () {
			//后
		})()
);
