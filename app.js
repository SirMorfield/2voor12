const fs = require('fs')

let a = fs.readFileSync('./dictionary_nl.txt')
a = a.toString()

a = a.split('\n')
let b = ''

for (const line of a) {
	if (line.length == 12 && !line.match(/\s/))
		b += `${line}\n`
	}

fs.writeFileSync('out.txt', b)
