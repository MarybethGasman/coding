#! /usr/bin/env node

"use strict";

require("path")
var args = require("minimist")(process.argv.slice(2));

console.log(args);
console.log("hello world");
