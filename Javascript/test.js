function getRandomBetween(minimum, maximum) {
    console.log(a);
    return Math.floor(Math.random() * (maximum - minimum)) + minimum;
}

const person = {
    PI: 3.14,
}

Object.freeze(person);
person.PI = 11111;

console.log(person);