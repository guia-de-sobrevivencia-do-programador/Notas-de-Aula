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

const calcula = function (a, b, operacao) {

  if (operacao === 'soma') {
    return soma(a, b)
  } else if (operacao === 'sub') {
    return sub(a, b)
  } else if (operacao === 'mult') {
    return mult(a, b)
  } else if (operacao === 'div') {
    return div(a, b)
  } else if (operacao === 'pot') {
    return pot(a, b)
  } else {
    throw new Error('Operacao invalida')
  }
}

module.exports = {
  calcula
}
