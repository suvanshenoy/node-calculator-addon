const addon = require('./build/Release/calculator.node');

const calc = addon.createCalculator();

const handleDivide = (a, b) => {
  try {
    const result = calc.divide(a, b);
    if (result === null || result === undefined) {
      console.error('Error: Division by zero');
    } else {
      console.log(`Divide: ${a} / ${b} = ${result}`);
    }
  } catch (e) {
    console.error('Error:', e.message);
  }
}

console.log('Add: 3 + 2 =', calc.add(3, 2));
console.log('Subtract: 5 - 3 =', calc.subtract(5, 3));
console.log('Multiply: 4 * 2 =', calc.multiply(4, 2));

handleDivide(6, 2);
handleDivide(1, 0);
