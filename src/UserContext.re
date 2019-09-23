// our user context object. Where this goes or is passed down we will have access to the users context, if logged in or not.

// first create the context object with Anonymous user state as the initial value.
open Types;
let context = React.createContext(Anonymous);

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

