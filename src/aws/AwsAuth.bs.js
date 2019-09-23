// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var AwsAmplify = require("aws-amplify");
var PromiseMonad = require("bs-promise-monad/src/PromiseMonad.bs.js");
var AuthErrors$ReactHooksTemplate = require("./AuthErrors.bs.js");

function getUser(param) {
  return PromiseMonad.$great$great$pipe(PromiseMonad.$great$great$eq(AwsAmplify.Auth.currentAuthenticatedUser(), (function (response) {
                    return PromiseMonad.$$return(/* Ok */Block.__(0, [response]));
                  })), (function (err) {
                return PromiseMonad.$$return(/* Error */Block.__(1, [err]));
              }));
}

function signOut(param) {
  console.log("SIGNING_OUT");
  AwsAmplify.Auth.signOut();
  return /* () */0;
}

function signIn(username, password) {
  var signInValues = Js_dict.fromList(/* :: */[
        /* tuple */[
          "username",
          username
        ],
        /* :: */[
          /* tuple */[
            "password",
            password
          ],
          /* [] */0
        ]
      ]);
  return AwsAmplify.Auth.signIn(signInValues).then((function (result) {
                  console.log("SIGNUP_RESULT", result);
                  return Promise.resolve(/* () */0);
                })).catch((function (err) {
                return Promise.resolve((console.log(err), /* () */0));
              }));
}

function signUp(username, password, email, phone_number) {
  var attributes = Js_dict.fromList(/* :: */[
        /* tuple */[
          "email",
          email
        ],
        /* :: */[
          /* tuple */[
            "phone_number",
            phone_number
          ],
          /* [] */0
        ]
      ]);
  var authValues = Js_dict.fromList(/* :: */[
        /* tuple */[
          "username",
          username
        ],
        /* :: */[
          /* tuple */[
            "password",
            password
          ],
          /* :: */[
            /* tuple */[
              "attributes",
              attributes
            ],
            /* [] */0
          ]
        ]
      ]);
  console.log("Running SIGNUP");
  console.log("authValues", authValues);
  console.log("SIGNUP_JSON", authValues);
  return AwsAmplify.Auth.signUp(authValues).then((function (result) {
                  console.log("result", result);
                  return Promise.resolve(/* SignedUp */0);
                })).catch((function (err) {
                console.log("Error", AuthErrors$ReactHooksTemplate.errorToObj(err));
                return Promise.resolve(/* SignUpFailure */Block.__(2, [AuthErrors$ReactHooksTemplate.errorToObj(err)]));
              }));
}

function confirmSignUp(username, confirmationCode) {
  var confirmValues = Js_dict.fromList(/* :: */[
        /* tuple */[
          "username",
          username
        ],
        /* :: */[
          /* tuple */[
            "confirmationCode",
            confirmationCode
          ],
          /* [] */0
        ]
      ]);
  return AwsAmplify.Auth.confirmSignUp(confirmValues).then((function (result) {
                  console.log("SIGNUP_RESULT", result);
                  return Promise.resolve(/* () */0);
                })).catch((function (err) {
                return Promise.resolve((console.log(err), /* () */0));
              }));
}

exports.getUser = getUser;
exports.signOut = signOut;
exports.signIn = signIn;
exports.signUp = signUp;
exports.confirmSignUp = confirmSignUp;
/* aws-amplify Not a pure module */