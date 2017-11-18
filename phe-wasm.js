'use strict'

/* global WebAssembly */

const wasm = require('./wasm/phe.wasm.js')

// Define the module environment:
var memory = new WebAssembly.Memory({ 'initial': 256 })
var table = new WebAssembly.Table({ 'initial': 0, 'element': 'anyfunc' })
var imports = { env: { memory, memoryBase: 0, table, tableBase: 0 } }

const { _evaluate_5cards, _evaluate_6cards, _evaluate_7cards } = wasm({ imports }).exports

module.exports = {
    evaluator5: _evaluate_5cards
  , evaluator6: _evaluate_6cards
  , evaluator7: _evaluate_7cards
}
