[@bs.module "aws-amplify-react"]
// takes a react component and returns a react component with the same signature
external withAuthenticator:
  (React.component('props), bool) => React.component('props) =
  "withAuthenticator";