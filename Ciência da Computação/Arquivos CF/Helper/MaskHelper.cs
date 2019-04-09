using System;
using Android.Widget;

namespace BrasilCardAppLojistaXamarin.Droid.Helper
{

    /// <summary>
    /// Classe que permite mascarar campos como CPF, CNPJ, Telefone, CEP entre outros.
    /// </summary>
    public class MaskHelper : Java.Lang.Object, Android.Text.ITextWatcher {

        public const String CPF_MASK = "###.###.###-##";
        public const String CELULAR_MASK = "(##)#####-####";
        public const String TELEFONE_MASK = "(##)####-####";
        public const String CEP_MASK = "#####-###";
        public const String DATA_MASK = "##/##/####";
        public const String CREDIT_CARD_MASK = "####.####.####.####";

        protected readonly EditText _editText;
        protected string _mask;
        protected bool isUpdating;
        protected string old = "";

        /// <summary>
        /// Construtor
        /// </summary>
        /// <param name="editText">Campo a ser mascarado</param>
        /// <param name="mask">mascara</param>
        public MaskHelper(EditText editText, string mask) {

            _editText = editText;
            _mask = mask;
        }

        /// <summary>
        /// Retorna o valor do campo sem mascara
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string Unmask(string s) {

            return s.Replace(".", "").Replace("-", "")
                .Replace("/", "").Replace("(", "")
                .Replace(")", "");
        }

        /// <summary>
        /// Callback depois de alterar o campo
        /// </summary>
        /// <param name="s"></param>
        public void AfterTextChanged(Android.Text.IEditable s) {
        }

        /// <summary>
        /// Callback antes de alterar o campo
        /// </summary>
        /// <param name="s"></param>
        /// <param name="start"></param>
        /// <param name="count"></param>
        /// <param name="after"></param>
        public void BeforeTextChanged(Java.Lang.ICharSequence s, int start, int count, int after) {
        }

        /// <summary>
        /// Callback chamado a alterar o campo
        /// </summary>
        /// <param name="s"></param>
        /// <param name="start"></param>
        /// <param name="before"></param>
        /// <param name="count"></param>
        public virtual void OnTextChanged(Java.Lang.ICharSequence s, int start, int before, int count) {

            string str = Unmask(s.ToString());
            string mascara = "";

            if (isUpdating) {

                old = str;
                isUpdating = false;
                return;
            }

            int i = 0;

            foreach (var m in _mask.ToCharArray()) {

                if ((m != '#')) {

                    if (i == str.Length && str.Length < old.Length)
                    {
                        continue;
                    }
                    mascara += m;
                    continue;
                }
                
                try {

                    mascara += str[i];
                }
                catch {

                    break;
                }
                i++;
            }

            if (mascara.Length > 1)
            {
                char last_char = mascara[mascara.Length - 1];
                bool hadSign = false;

                while (Char.IsLetterOrDigit(last_char) && (str.Length == old.Length) && (mascara.Length - 2 >= 0))
                {
                    mascara = mascara.Substring(0, mascara.Length - 1);
                    last_char = mascara[mascara.Length - 1];
                    hadSign = true;
                }

                if (mascara.Length > 0 && hadSign)
                {
                    mascara = mascara.Substring(0, mascara.Length - 1);
                }
            }

            isUpdating = true;

            _editText.Text = mascara;

            _editText.SetSelection(mascara.Length);
        }
    }
}