var videoEle = document.querySelector("#marvel");
console.log(videoEle);

videoEle.ontimeupdate = () => {
	// console.log(videoEle.currentTime);
};
videoEle.onclick = (e) => {
	e.preventDefault();
};
