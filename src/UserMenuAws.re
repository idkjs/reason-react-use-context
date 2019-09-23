open Types;
let str = React.string;

[@react.component]
let make = () => {
  let (user, dispatch) = UserContext.useUser();
  let (userName, setUserName) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  // this is the hook which call the UserContext dispatch method
  let handleLogIn = () => dispatch(UserLoggedIn(userName));
  let handleLogOut = () => {
    AwsAuth.signOut();
    dispatch(UserLoggedIn(userName));
  };
  let signIn = () => {
    Js.log2(userName, password);
    Js.Promise.(
      AwsAuth.signIn(~username=userName, ~password)
      |> then_(result => {
           Js.log2("successfully signed in", result);
           handleLogIn();
           resolve();
         })
      |> catch(err => {
           Js.log(err);
           let errMsg = "error signing up..." ++ Js.String.make(err);
           Js.log(errMsg);
           resolve();
         })
      |> ignore
    );
  };
  switch (user) {
  | Anonymous =>
    <form
      className="user-form"
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        signIn();
      }}>
      <input
        className="login-input"
        placeholder="User name"
        value=userName
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          setUserName(_ => value);
        }}
      />
      <input
        className="login-input"
        placeholder="Password"
        value=password
        onChange={e => {
          let value = ReactEvent.Form.target(e)##value;
          setPassword(_ => value);
        }}
      />
      <button type_="submit"> {str("Log in")} </button>
    </form>
  | LoggedIn(userName) =>
    <div className="user-form">
      <span className="logged-in">
        {str("Logged in as: ")}
        <b> {str(userName)} </b>
      </span>
      <button
        onClick={e => {
          ReactEvent.Mouse.preventDefault(e);
          handleLogOut();
        }}>
        {str("Log out")}
      </button>
    </div>
  };
};