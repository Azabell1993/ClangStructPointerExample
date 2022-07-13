const fs = require('fs');
const { addSyntheticLeadingComment } = require('typescript');
// loading wasm to buffer
let buffer = fs.readFileSync('./add.wasm');
// instantiate the wasm
const wasm_module = new  WebAssembly.Instance(
    new WebAssembly.Module(buffer));  
// extract the function 
const { AddResult } = wasm_module.exports;
console.log(AddResult(10,20));