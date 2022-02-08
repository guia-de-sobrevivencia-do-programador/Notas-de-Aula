const { pow } = require('mathjs')

const soma = (a, b) => a + b
const sub = (a, b) => a - b
const mult = (a, b) => a * b
const div = (a, b) => a / b

const pot = (a, b) => pow(a, b)

module.exports = {
  soma,
  sub,
  mult,
  div,
  pot,
}
