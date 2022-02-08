const calculadora = require('./calculadora')

test('deve somar dois numeros', () => {
  const resultado = calculadora.calcula(1, 2, 'soma')

  expect(resultado).toBe(3)
})