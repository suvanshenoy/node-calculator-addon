## Nodejs Calculator Addon

#### Installation and Building:
**Using yarn (Easiest) :**
- Install a package manager like yarn following instructions at https://classic.yarnpkg.com/lang/en/docs/install/#debian-stable
- To get the dependencies and build the project use 
```bash
   cd node-calculator-addon ; yarn
```

**Using npm or bun :**
- Install npm by following instructions at

   https://github.com/npm/cli

- build project using:
```bash
   npm i
   npx node-gyp configure
   npm run build
```
####            or
- Install bun following instructions  at :

   https://bun.sh

- build project using:
```bash
   bun i
   bunx node-gyp configure
   bun build
```

**Running :**
- To run the project use
```bash
  node main.js
```
