const express = require('express')
const ip = require('ip')

const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send(`Hello, my IP is: ${ip.address()}`)
})

app.listen(port, () => {
  console.log(`App rodando na porta: ${port}`)
})