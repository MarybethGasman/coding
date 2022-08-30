var app = (function App() {
	var publicAPI = { addMessage, getCurrentUser };

	var btn = document.querySelector("button#reply");
	btn?.addEventListener("click", addMessage);

	function getCurrentUser() {
		return fetch("http://127.0.0.1:3000/user/1").then((res) => res.json());
	}

	async function addMessage() {
		var time = new Date().toDateString();
		var avatar, name;
		var content = getContent();
		await getCurrentUser()
			.then((user) => {
				({ name, avatar } = user);
			})
			.catch((err) => {
				console.log(err);
			});

		var parent = document.body;
		var message = `<div class="message">
			<div class="message__user-info">
				<img
					src="${avatar}"
					alt=""
					class="avatar message__avatar"
				/>
				<div class="message__name">${name}</div>
				<span class="message__time">${time}</span>
			</div>
			<div class="message__content">${content}</div>
		</div>`;
		appendHtml(parent, message);
		function getContent() {
			return "了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开了法律开始大家弗兰克发牢骚大家方式了打开";
		}
	}
	function appendHtml(el, str) {
		var div = document.createElement("div");
		div.innerHTML = str;
		while (div.children.length > 0) {
			el.appendChild(div.children[0]);
		}
	}
	return publicAPI;
})();

// console.log(app.getCurrentUser());
