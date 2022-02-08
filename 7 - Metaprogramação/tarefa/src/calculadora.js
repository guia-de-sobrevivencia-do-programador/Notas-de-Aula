const { pow } = require('mathjs')

const soma = function (a, b) {
  return a + b;
}

const sub = function (a, b) {
  return a - b;
}

const mult = function (a, b) { 
  return a * b 
}

const div = function (a, b) { 
  return a / b 
}

const pot = function (a, b) { 
  return pow(a, b) 
}

module.exports = {
  soma,
  sub,
  mult,
  div,
  pot,
}
