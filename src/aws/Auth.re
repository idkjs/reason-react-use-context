  [@bs.module "aws-amplify"] [@bs.scope "Auth"]
  external currentAuthenticatedUser: unit => Js.Promise.t('a) =
    "currentAuthenticatedUser";
  let currentAuthenticatedUser =
    currentAuthenticatedUser()
    |> Js.Promise.then_(res => Js.Promise.resolve(res));