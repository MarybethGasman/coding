window.addEventListener("unhandledrejection", (event) => {
	event.preventDefault();
	probeSend(event);
});
window.addEventListener(
	"error",
	function (msg) {
		console.log(msg);
		probeSend(msg);
	},
	true
);
window.onerror = function (msg, url, row, col, error) {
	console.log(msg, url, row, col, error);
	var obj = { msg, url, row, col, error };

	probeSend(msg);
	return true;
};
function probeSendDeep(data) {
	var srcUrl = `probe.gif?${JSON.stringify(data)}`;
	new Image().src = srcUrl;
}
function probeSend(data) {
	var srcUrl = "probe.gif?";
	for (const key in data) {
		srcUrl += `${key}=${data[key]}&`;
		// console.log(key);
		// console.log(data[key]);
	}
	srcUrl.substring(0, srcUrl.length - 1);
	new Image().src = srcUrl;
	//`./haorooms.gif?${key}=${value}&${Math.random()} `
}
// probeSend({ id: 1, title: "vue进阶", author: "尤雨溪", date: "16684732894" });
// new Promise((resolve, reject) => {
// 	reject("promise 错误");
// });
// throw error;
