[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signOut: unit => unit = "signOut";

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external currentAuthenticatedUser: unit => Js.Promise.t(Js.Json.t) =
  "currentAuthenticatedUser";
let getUser = () => {
  PromiseMonad.(
    Belt.Result.(
      currentAuthenticatedUser()
      >>= (response => Ok(response) |> return)
      >>| (err => Error(err) |> return)
    )
  );
};
let signOut = () => {
  Js.log("SIGNING_OUT");
  signOut();
};

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signIn: Js.Json.t => Js.Promise.t(Js.Json.t) = "signIn";

let signIn = (~username, ~password) => {
  let signInValues: Js.Dict.t(Js.Json.t) =
    Js.Dict.fromList([
      ("username", Js.Json.string(username)),
      ("password", Js.Json.string(password)),
    ]);
  let json = Js.Json.object_(signInValues);
  Js.Promise.(
    signIn(json)
    |> then_(result => {
         Js.log2("SIGNUP_RESULT", result);
         /* Js.log(Js.Dict.get(signUpResult, "userConfirmed"));
            Js.log(Js.Dict.keys(signUpResult));
            let keys = Js.Dict.keys(signUpResult);
            Js.log2("keys",keys); */
         resolve();
       })
    |> catch(err => resolve(Js.log(err)))
  );
};
// SignUp

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external signUp: Js.Json.t => Js.Promise.t(Js.Json.t) = "signUp";

let signUp =
    (
      ~username: string,
      ~password: string,
      ~email: string,
      ~phone_number: string,
    ) => {
  let attributes: Js.Dict.t(Js.Json.t) =
    Js.Dict.fromList([
      ("email", Js.Json.string(email)),
      ("phone_number", Js.Json.string(phone_number)),
    ]);
  let authValues =
    Js.Dict.fromList([
      ("username", Js.Json.string(username)),
      ("password", Js.Json.string(password)),
      ("attributes", Js.Json.object_(attributes)),
    ]);
  Js.log("Running SIGNUP");
  Js.log2("authValues", authValues);
  let json = Js.Json.object_(authValues);
  Js.log2("SIGNUP_JSON", json);
  AuthErrors.(
    Js.Promise.(
      signUp(json)
      |> then_(result => {
           Js.log2("result", result);
           resolve(SignedUp);
         })
      |> catch(err => {
           Js.log2("Error", errorToObj(err));
           resolve(SignUpFailure(errorToObj(err)));
         })
    )
  );
  // Js.Promise.(
  //   signUp(json)
  //   |> then_(result => {
  //        Js.log2("SIGNUP_RESULT", result);
  //        /* Js.log(Js.Dict.get(signUpResult, "userConfirmed"));
  //        Js.log(Js.Dict.keys(signUpResult));
  //        let keys = Js.Dict.keys(signUpResult);
  //        Js.log2("keys",keys); */
  //        resolve();
  //      })
  //   |> catch(err => resolve(Js.log(err)))
  // );
};
// SignUp Confirmation

[@bs.module "aws-amplify"] [@bs.scope "Auth"]
external confirmSignUp: Js.Json.t => Js.Promise.t(Js.Json.t) =
  "confirmSignUp";

let confirmSignUp = (~username, ~confirmationCode) => {
  let confirmValues: Js.Dict.t(Js.Json.t) =
    Js.Dict.fromList([
      ("username", Js.Json.string(username)),
      ("confirmationCode", Js.Json.string(confirmationCode)),
    ]);
  let json = Js.Json.object_(confirmValues);

  Js.Promise.(
    confirmSignUp(json)
    |> then_(result => {
         Js.log2("SIGNUP_RESULT", result);
         /* Js.log(Js.Dict.get(signUpResult, "userConfirmed"));
            Js.log(Js.Dict.keys(signUpResult));
            let keys = Js.Dict.keys(signUpResult);
            Js.log2("keys",keys); */
         resolve();
       })
    |> catch(err => resolve(Js.log(err)))
  );
};