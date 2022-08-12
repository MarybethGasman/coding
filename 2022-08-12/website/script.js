// node.js, "classic" way:
import MarkdownIt from "markdown-it";
import hljs from "highlight.js";
import "highlight.js/styles/github.css";

var md = MarkdownIt({
	highlight: function (str, lang) {
		if (lang && hljs.getLanguage(lang)) {
			try {
				return (
					'<pre class="hljs"><code>' +
					hljs.highlight(str, {
						language: lang,
						ignoreIllegals: true,
					}).value +
					"</code></pre>"
				);
			} catch (__) {}
		}

		return (
			'<pre class="hljs"><code>' +
			md.utils.escapeHtml(str) +
			"</code></pre>"
		);
	},
});

var result = md.render("### 标题\n ``` js\n console.log('helloworld');\nconsole.log('hhh');\n ``` ");

console.log(result);
appendHtml(document.body, result);
function appendHtml(el, str) {
	var div = document.createElement("div");
	div.innerHTML = str;
	while (div.children.length > 0) {
		el.appendChild(div.children[0]);
	}
}
