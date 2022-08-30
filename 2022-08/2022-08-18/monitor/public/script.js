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
probeSend(performance.timing);
var userLog = (function () {
	//
	// Private variables
	//
	var defaults = {
			// Available functionality
			clickCount: true,
			clickDetails: true,
			mouseMovement: true,
			context: true,
			keyLogger: true,

			// Action Item
			actionItem: {
				processOnAction: false,
				selector: "",
				event: "",
			},
			processTime: 15,
			processData: function (results) {
				console.log(results);
			},
		},
		// End results, what is shown to the user
		results = {
			userInfo: {
				appCodeName: navigator.appCodeName || "",
				appName: navigator.appName || "",
				vendor: navigator.vendor || "",
				platform: navigator.platform || "",
				userAgent: navigator.userAgent || "",
			},
			time: {
				totalTime: 0,
				timeOnPage: 0,
			},
			clicks: {
				clickCount: 0,
				clickDetails: [],
			},
			mouseMovements: [],
			contextChange: [],
			keyLogger: [],
		},
		support = !!document.querySelector && !!document.addEventListener,
		settings;

	// Helper Functions
	var helperActions = {
		/**
		 * Set the timer interval, will increment time on page if the user is
		 * active on the page, totalTime counter always increments
		 * @private
		 */
		timer: function () {
			window.setInterval(function () {
				if (document["visibilityState"] === "visible") {
					results.time.timeOnPage++;
				}
				results.time.totalTime++;
			}, 1000);
		},
		/**
		 * Detect the X,Y coordinates of the mouse movement
		 * @private
		 */
		mouseMovement: function () {
			document.addEventListener("mousemove", function () {
				results.mouseMovements.push({
					timestamp: Date.now(),
					x: event.pageX,
					y: event.pageY,
				});
			});
		},
		/**
		 * Check if the user is navigating to a different page
		 * @private
		 */
		contextChange: function () {
			document.addEventListener("visibilitychange", function () {
				results.contextChange.push({
					timestamp: Date.now(),
					type: document["visibilityState"],
				});
			});
		},
		/**
		 * Log the pasted information and keys pressed
		 * @private
		 */
		keyLogger: function () {
			document.addEventListener("paste", function () {
				var pastedText = undefined;
				// Get Pasted Text
				if (window.clipboardData && window.clipboardData.getData) {
					pastedText = window.clipboardData.getData("Text");
				} else if (event.clipboardData && event.clipboardData.getData) {
					pastedText = event.clipboardData.getData("text/plain");
				}

				if (!!pastedText) {
					results.keyLogger.push({
						timestamp: Date.now(),
						data: pastedText,
						type: "paste",
					});
				}
			});
			document.addEventListener("keyup", function () {
				var charCode = event.keyCode || event.which,
					charString = String.fromCharCode(charCode);

				results.keyLogger.push({
					timestamp: Date.now(),
					data: charString,
					type: "keypress",
				});
			});
		},
	};

	/**
	 * Merge defaults with options
	 * @private
	 * @param {Object} default settings
	 * @param {Object} user options
	 * @returns {Object} merged object
	 */
	function getSettings(defaults, options) {
		var option;
		for (option in options) {
			if (options.hasOwnProperty(option)) {
				defaults[option] = options[option];
			}
		}
		return defaults;
	}

	/**
	 * Initialize the event listeners
	 * @public
	 * @param {Object} user options
	 */
	function init(options) {
		if (!support) return;

		// Extend default options
		if (options && typeof options === "object") {
			settings = getSettings(defaults, options);
		}

		document.addEventListener("DOMContentLoaded", function () {
			// Countdown Timer
			window.setInterval(function () {
				if (document["visibilityState"] === "visible") {
					results.time.timeOnPage++;
				}
				results.time.totalTime++;
				// Check if we need to process results
				if (
					settings.processTime > 0 &&
					results.time.totalTime % settings.processTime === 0
				) {
					processResults();
				}
			}, 1000);

			// Click registration, increment click counter and save click time+position
			if (settings.clickCount || settings.clickDetails) {
				document.addEventListener("mouseup", function () {
					if (settings.clickCount) {
						results.clicks.clickCount++;
					}
					if (settings.clickDetails) {
						results.clicks.clickDetails.push({
							timestamp: Date.now(),
							node: event.target.outerHTML,
							x: event.pageX,
							y: event.pageY,
						});
					}
				});
			}

			// Mouse movements
			if (settings.mouseMovement) {
				helperActions.mouseMovement();
			}

			// Check context change
			if (settings.context) {
				helperActions.contextChange();
			}

			// Key Logger
			if (settings.keyLogger) {
				helperActions.keyLogger();
			}

			// Event Listener to porcess
			if (settings.actionItem.processOnAction) {
				var node = document.querySelector(settings.actionItem.selector);
				if (!!!node) throw new Error("Selector was not found.");
				node.addEventListener(settings.actionItem.event, function () {
					return processResults();
				});
			}
		});
	}

	/**
	 * Calls provided function with results as parameter
	 * @public
	 */
	function processResults() {
		if (settings.hasOwnProperty("processData")) {
			return settings.processData.call(undefined, results);
		}
		return false;
	}

	// Module pattern, only expose necessary methods
	return {
		init: init,
		processResults: processResults,
	};
})();
userLog.init({
	// Available functionality
	clickCount: true,
	clickDetails: true,
	mouseMovement: true,
	context: true,
	keyLogger: true,

	// Action Item
	actionItem: {
		processOnAction: false,
		selector: "",
		event: "",
	},
	processTime: 15,
	processData: function (results) {
		console.log(results);
		probeSendDeep(results);
	},
});
