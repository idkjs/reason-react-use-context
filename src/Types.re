/* Create provider and context

   We will start with these steps:

       Create context,
       Create provider component,
       Create reusable hook to access context value.

   We need to know whether the user using our app is anonymous or logged in, and what actions can change this, so let's start with a few types: */

// to be used in a state/reducer setup as state
type user =
  | Anonymous
  | LoggedIn(string);
/* to be used in a state/reducer setup as actions*/
type userAction =
  | UserLoggedIn(string)
  | UserLoggedOut;