/* our user context object. Where this goes or is passed down we will have access to the users context, if logged in or not. */
open Types;
// define a type for our dispatch function. This taka a userAction and calls it.
type dispatch = userAction => unit;
// `context value is a tuple of `user` type and `dispatch` type we just defined.
type contextValue = (user, dispatch);

// define our initial value of type context value which means its a tuple which takes a user and a dispatch function. As user we are passing Anonymouse from our Types.user. `dispatch` gets a userAction which is then called, here we pass `_` to tell the compiler to ignore this argument, the as the function call, we call `ignore()` which ignores the result of calling nothing. Note that the function, unit shape of the dispatch type is respected.

/* This is has the effect of making no changes when creating the context. Clever.
 */

let initValue: contextValue = (Anonymous, _ => ignore());

/* first create the context object with Anonymous user state as the initial value. */

// let context = React.createContext(Anonymous);
// pass initValue to createContext instead of Anonymous
let context = React.createContext(initValue);


/* not making this of type unit, by making callable with `()` will throw this error in browser but not in compiler
   `let useUser = React.useContext(context);`

   proper way to call: `let useUser = () => React.useContext(context);` */
/*  Error: Invalid hook call. Hooks can only be called inside of the body of a function component. This could happen for one of the following reasons:
    1. You might have mismatching versions of React and the renderer (such as React DOM)
    2. You might be breaking the Rules of Hooks
    3. You might have more than one copy of React in the same app
    See https://fb.me/react-invalid-hook-call for tips about how to debug and fix this problem. */

// create a hook we can call to access this context
let useUser = () => React.useContext(context);

/* Let's give our components possibility to update user data via context. We could pass the update function down as props, which will be back to prop-drilling approach, but a more fun way is to include dispatch in the context value itself.
   Pass dispatch in context

   Let's pass our dispatch along with user as context value. Knowing that dispatch accepts userAction and returns unit, we can modify the type of context value in UserContext.re: */
