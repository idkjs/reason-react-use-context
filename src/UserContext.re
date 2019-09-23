
open Types;

type dispatch = userAction => unit;
type contextValue = (user, dispatch);

type context = contextValue => React.Context.t(contextValue);


let initValue: contextValue = (Anonymous, _ => ignore());
let context = React.createContext(initValue);

let useUser = () => React.useContext(context);

