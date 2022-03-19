const { pow } = require('mathjs')

jest.mock('mathjs', () =>  {
    return {
        pow: jest.fn()
    }
})

const calculadora = require('./calculadora')

test('deve somar dois numeros', () => {
  const resultado = calculadora.calcula(1, 2, 'soma')

  expect(resultado).toBe(3)
})

test('deve subtrair dois numeros', () => {
  const resultado = calculadora.calcula(1, 2, 'sub')

  expect(resultado).toBe(-1)
})

test('deve multiplicar dois numeros', () => {
  const resultado = calculadora.calcula(3, 2, 'mult')

  expect(resultado).toBe(6)
})

test('deve dividir dois numeros', () => {
  const resultado = calculadora.calcula(10, 2, 'div')

  expect(resultado).toBe(5)
})

test('deve elevar um numero pelo outro', () => {
  const resultado = calculadora.calcula(2, 2, 'pot')

  expect(pow).toHaveBeenCalledWith(2,2)
})

test('deve retornar um erro numa operacao invalida', () => {
  expect(() => calculadora.calcula(2, 2, 'operacao_invalida')).toThrow(Error("Operacao invalida"))
})


