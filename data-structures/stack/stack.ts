const initializeStack = <T extends Array<unknown>>(initialValue: T) => {
  let _storage = [...initialValue];

  const peekAll = () => _storage;

  const push = (item: unknown) => {
    _storage = [..._storage, item];
    return peekAll();
  };

  const pop = () => {
    _storage = _storage.slice(0, _storage.length - 1);
    return peekAll();
  };

  const peek = () => {
    return _storage[_storage.length - 1];
  };

  const erase = () => {
    _storage = [];
    return _storage;
  };

  return {
    peekAll,
    push,
    pop,
    peek,
    erase,
  };
};

const { erase, peek, peekAll, pop, push } = initializeStack([1, 2, "c"]);

push(10);

console.log(peekAll());
console.log(peek());
pop();
console.log(peekAll());
console.log(peek());
erase();
console.log(peekAll());
