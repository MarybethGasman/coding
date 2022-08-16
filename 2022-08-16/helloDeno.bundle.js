// deno-fmt-ignore-file
// deno-lint-ignore-file
// This code was bundled using `deno bundle` and it's not recommended to edit it manually

const noColor = globalThis.Deno?.noColor ?? true;
let enabled = !noColor;
function code(open, close) {
    return {
        open: `\x1b[${open.join(";")}m`,
        close: `\x1b[${close}m`,
        regexp: new RegExp(`\\x1b\\[${close}m`, "g")
    };
}
function run(str, code) {
    return enabled ? `${code.open}${str.replace(code.regexp, code.open)}${code.close}` : str;
}
function bold(str) {
    return run(str, code([
        1
    ], 22));
}
function italic(str) {
    return run(str, code([
        3
    ], 23));
}
function red(str) {
    return run(str, code([
        31
    ], 39));
}
function bgBlue(str) {
    return run(str, code([
        44
    ], 49));
}
new RegExp([
    "[\\u001B\\u009B][[\\]()#;?]*(?:(?:(?:[a-zA-Z\\d]*(?:;[-a-zA-Z\\d\\/#&.:=?%@~_]*)*)?\\u0007)",
    "(?:(?:\\d{1,4}(?:;\\d{0,4})*)?[\\dA-PR-TZcf-ntqry=><~]))", 
].join("|"), "g");
console.log(bgBlue(italic(red(bold("Hello Deno!")))));
