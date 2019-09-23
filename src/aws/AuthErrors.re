type userT = {. "challengeName": Js.Nullable.t(string)};
// [@bs.module "@aws-amplify/auth/lib"] [@bs.scope "default"]
// external confirmSignUp: (string, string) => Js.Promise.t(unit) =
//   "confirmSignUp";

// [@bs.module "@aws-amplify/auth/lib"] [@bs.scope "default"]
// external signUp: (string, string, string) => Js.Promise.t(unit) = "signUp";
type errorT =
  | Message(string)
  | Response(
      {
        .
        "code": Js.Nullable.t(string),
        "message": Js.Nullable.t(string),
        "name": Js.Nullable.t(string),
      },
    );

type signUpResult =
  | SignedUp
  | SignUpSuccessful(userT)
  | SignUpChallenge(string, userT)
  | SignUpFailure(errorT)
  | SignInConfirmation(string);

type confirmChallengResult =
  | Confirmed
  | ConfirmError(errorT);
/*
 Convert a JS AWS error into a typed obj
 */
let errorToObj = err =>
  switch (err |> Obj.magic |> Js.Json.classify) {
  | Js.Json.JSONObject(obj) =>
    let (code, message, name) =
      ["code", "message", "name"]
      |> List.map(Js.Dict.get(obj))
      |> List.map(Js.Option.andThen((. o) => Js.Json.decodeString(o)))
      |> List.map(Js.Nullable.fromOption)
      |> (
        l =>
          switch (l) {
          | [c, m, n] => (c, m, n)
          | _ => (Js.Nullable.null, Js.Nullable.null, Js.Nullable.null)
          }
      );
    Response({"code": code, "message": message, "name": name});
  | Js.Json.JSONString(str) => Message(str)
  | _ =>
    let errMsg = err |> Js.Json.stringifyAny |> Js.Option.getWithDefault("");
    Message("An error occurred: " ++ errMsg);
  };

  // let signUp = (~username: string, ~password: string, ~attributes: string) =>
  // Js.Promise.(
  //   signUp(username, password, attributes)
  //   |> then_(result => {
  //        Js.log2("result", result);
  //        resolve(SignedUp);
  //      })
  //   |> catch(err => {
  //        Js.log2("Error", err);
  //        resolve(SignUpFailure(errorToObj(err)));
  //      })
  // );