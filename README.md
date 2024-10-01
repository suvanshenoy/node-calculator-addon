## Nodejs Calculator Addon

#### Installation and Building:
Using yarn (Easiest):
- Install a package manager like yarn following instructions at https://classic.yarnpkg.com/lang/en/docs/install/#debian-stable
- To get the dependencies and build the project use 
```
   yarn
```
in the root directory ie; node_calculator_addon

Using npm or bun:
- Install npm following instructions at https://github.com/npm/cli
- build project using:
```
   npm i
   npx node-gyp configure
   npm run build
```
###     or 
- Install bun following instructions  at https://bun.sh
- build project using:
```
   bun i
   bunx node-gyp configure
   bun build
```

#### Running
- To run the project use
```
  node main.js
```
