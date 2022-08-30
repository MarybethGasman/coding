import { bgBlue, red, bold, italic } from "https://deno.land/x/std@0.65.0/fmt/colors.ts";

console.log(bgBlue(italic(red(bold("Hello Deno!")))));