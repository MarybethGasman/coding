import { defineConfig } from "vite";
import path from "path";
import eslint from "vite-plugin-eslint";
export default defineConfig({
	plugins: [eslint()],
	root: path.resolve(__dirname, "src"),
	resolve: {
		alias: {
			"~bootstrap": path.resolve(__dirname, "node_modules/bootstrap"),
		},
	},
	server: {
		port: 8080,
		hot: true,
	},
});
