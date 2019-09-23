// create a context provider which will pass the context to your components where you want it. Call the React.Context api's provider function and pass it the context we want to use here. UserContext.context.

let make = React.Context.provider(UserContext.context);

// use `makeProps` to convert our reason context object to ReactJs props object it expects. This is what happens automatically when we use `[@react.component]` in our modules. makeProps is a function that takes some value and passes to children, hence the props `~value, ~children`. This componenet does same thing but keep reading...

/* React.Context.provider already generates a react component that uses props as a JS object, but we want to use it as a reason component with named args. That's why we create makeProps by hand and it will tell bucklescript how to translate our named args into a JS object, consumed as props by the JS component. And in order to create an object that will compile cleanly to a JS object, we use bucklescript Object 2 bindings, that look like this: */

/* calling without `unit` in the `args` like this:
   ```reason
   let makeProps = (~value, ~children, ()) => {
     "value": value,
     "children": children,
   };
   ```

   Compiler will throw this error:
   ```
    We've found a bug for you!
     /Users/prisc_000/Downloads/practical-reason-react-maggy/src/Root.re 18:4-15

     16 │ let make = () => {
     17 │   let (state, dispatch) = React.useReducer(reducer, {user: Anonymous})
          ;
     18 │   <UserProvider value={state.user}> <Page /> </UserProvider>;
     19 │ };

     This function has type
       (~value: 'a, ~children: 'b) => {. "children": 'b, "value": 'a}
     It only accepts 2 arguments; here, it's called with more.

   FAILED: subcommand failed.
   >>>> Finish compiling(exit: 1)

   ``` */
let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};