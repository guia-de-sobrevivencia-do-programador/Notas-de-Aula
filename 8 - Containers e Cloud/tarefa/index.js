const express = require('express')
const ip = require('ip')

const logger = require('./logger')

const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send(`Hello, my IP is: ${ip.address()}`)
})

app.listen(port, () => {
  logger.info(`App rodando na porta: ${port}`)
})