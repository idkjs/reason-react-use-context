/* Update value in context

   Now, we want to use our Provider component and give it the user info, that we can update when the user logs in or logs out.

   The important thing to understand here, is that if we want to update the value in context and propagate the update to subscriber-components, the value needs to be on the state of some component. This component needs to render the provider component with the value from its own state. */
open Types;
type state = {user};

let reducer = (_, action) =>
  switch (action) {
  | UserLoggedIn(userName) => {user: LoggedIn(userName)}
  | UserLoggedOut => {user: Anonymous}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, {user: Anonymous});

    React.useEffect1(
      () => {
        let userData = Auth.currentAuthenticatedUser;
        Js.log2("userData", userData);
        None;
      },
      [||] // This is the key as this effect will be independent of any change in props.
    );
  <UserProvider value=(state.user, dispatch)> <> <Header /> <main> <Page /> </main> </> </UserProvider>;
};