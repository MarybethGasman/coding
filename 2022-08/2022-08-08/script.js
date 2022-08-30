var btn = document.querySelector("#sidebar-btn");
var sidebar = document.querySelector("#sidebar");
btn?.addEventListener("click", () => {
	sidebar?.setAttribute(
		"class",
		(sidebar.className + " show")
			.split(" ")
			.filter((elem, pos, self) => {
				return self.lastIndexOf(elem) == pos;
			})
			.join(" ")
	);
});
var app = document.querySelector("#app");

app?.addEventListener("click", () => {
	sidebar?.setAttribute(
		"class",
		sidebar.className
			.split(" ")
			.filter((item) => item !== "show")
			.join(" ")
	);
});
