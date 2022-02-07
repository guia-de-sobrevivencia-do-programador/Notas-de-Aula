const calculadora = require('./calculadora')

describe('testes para soma', () =>  {
  test('deve somar dois numeros', () => {
    const resultado = calculadora.soma(1, 2)

    expect(resultado).toBe(3)
  })
})