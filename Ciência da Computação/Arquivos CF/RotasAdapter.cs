using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Util;
using Android.Views;
using Android.Widget;
using BrasilCardAppLojistaXamarin.Bean;

namespace BrasilCardAppLojistaXamarin.Droid.View
{

    class RotasAdapter : BaseAdapter<Rota>
    {
        IList<Rota> items;
        Activity context;
        string cpf;
        public RotasAdapter(Activity context, IList<Rota> items)
       : base()
        {
            this.context = context;
            this.items = items;
        }
        public override long GetItemId(int position)
        {
            return position;
        }
        public override Rota this[int position]
        {
            get { return items[position]; }
        }
        public override int Count
        {
            get { return items.Count; }
        }

        public override Android.Views.View GetView(int position, Android.Views.View convertView, ViewGroup parent)
        {
            var item = items[position];
            Android.Views.View view = convertView;
            if (view == null)
                view = context.LayoutInflater.Inflate(Resource.Layout.lista_rotas, null);
            
            view.FindViewById<TextView>(Resource.Id.txtLocal).Text = items[position].local;
            view.FindViewById<TextView>(Resource.Id.txtHorario).Text = items[position].horario;
            view.FindViewById<TextView>(Resource.Id.txtVeiculo).Text = items[position].veiculo;
           
    
            return view;
        }
        static string GetMd5Hash(MD5 md5Hash, string input)
        {
            byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(input));
            StringBuilder sBuilder = new StringBuilder();
            for (int i = 0; i < data.Length; i++)
            {
                sBuilder.Append(data[i].ToString("x2"));
            }
            return sBuilder.ToString();
        }
    }
}